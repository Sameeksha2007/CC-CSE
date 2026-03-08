# Activity 5: Hash Tables
## Code
```C++
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int capacity;
    int currentSize;
    int collisionCount;

    int hashFunction(const string& key) const {
        long long hash = 0;
        for (char c : key)
            hash = hash * 31 + c;
        long long idx = hash % capacity;
        if (idx < 0) idx += capacity;
        return (int)idx;
    }

    void rehash() {
        capacity = capacity * 2;
        collisionCount = 0;
        vector<list<pair<string, int>>> oldTable = table;
        table.assign(capacity, list<pair<string, int>>());
        currentSize = 0;
        for (auto& bucket : oldTable)
            for (auto& kv : bucket)
                insert(kv.first, kv.second);
    }

public:
    HashTable(int size = 11) {
        capacity       = size;
        currentSize    = 0;
        collisionCount = 0;
        table.assign(capacity, list<pair<string, int>>());
    }

    void insert(const string& key, int value) {
        if ((double)(currentSize + 1) / capacity > 0.75)
            rehash();

        int idx = hashFunction(key);

        // Update if key already exists
        for (auto& kv : table[idx]) {
            if (kv.first == key) { kv.second = value; return; }
        }

        // Collision if bucket not empty
        if (!table[idx].empty()) collisionCount++;

        table[idx].push_back({key, value});
        currentSize++;
    }

    bool remove(const string& key) {
        int idx = hashFunction(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
            if (it->first == key) {
                table[idx].erase(it);
                currentSize--;
                return true;
            }
        }
        return false;
    }

    int search(const string& key) const {
        int idx = hashFunction(key);
        for (auto& kv : table[idx])
            if (kv.first == key) return kv.second;
        throw runtime_error("Key not found: " + key);
    }

    double loadFactor()    const { return (double)currentSize / capacity; }
    int    size()          const { return currentSize; }
    bool   isEmpty()       const { return currentSize == 0; }
    int    getCollisions() const { return collisionCount; }
    int    getCapacity()   const { return capacity; }

    int maxBucketSize() const {
        int mx = 0;
        for (auto& b : table)
            if ((int)b.size() > mx) mx = (int)b.size();
        return mx;
    }

    double avgBucketLength() const {
        int nonEmpty = 0;
        for (auto& b : table) if (!b.empty()) nonEmpty++;
        if (nonEmpty == 0) return 0;
        return (double)currentSize / nonEmpty;
    }

    void printStats(const string& label) const {
        cout << "\n=== " << label << " ===\n";
        cout << "  Capacity    : " << capacity         << "\n";
        cout << "  Elements    : " << currentSize      << "\n";
        cout << "  Load Factor : " << loadFactor()     << "\n";
        cout << "  Collisions  : " << collisionCount   << "\n";
        cout << "  Max bucket  : " << maxBucketSize()  << "\n";
        cout << "  Avg bucket  : " << avgBucketLength()<< "\n";
    }
};

// =============================================
//  main
// =============================================
int main() {

    // --- Part 5: Insert 100+ words ---
    HashTable ht;

    vector<string> words = {
        "apple","banana","cherry","date","elderberry","fig","grape",
        "honeydew","kiwi","lemon","mango","nectarine","orange","papaya",
        "quince","raspberry","strawberry","tangerine","ugli","vanilla",
        "watermelon","avocado","blueberry","cantaloupe","dragonfruit",
        "eggplant","guava","jackfruit","kumquat","lychee","mulberry",
        "olive","persimmon","pomegranate","rambutan","soursop","tamarind",
        "apricot","blackberry","coconut","durian","fennel","garlic",
        "horseradish","kale","leek","mushroom","nutmeg","oregano",
        "parsley","quinoa","rosemary","sage","thyme","turmeric","wasabi",
        "almond","basil","clove","dill","ginger","hibiscus","jasmine",
        "lavender","marjoram","nettle","peppermint","spearmint","tarragon",
        "acacia","bergamot","cardamom","dandelion","goldenrod","iris",
        "juniper","lotus","marigold","nasturtium","pansy","peony","poppy",
        "saffron","sunflower","violet","willow","aster","camellia",
        "dahlia","forsythia","gardenia","heather","indigo","ivy",
        "larkspur","mimosa","orchid","primrose","snapdragon","tulip",
        "wisteria","zinnia","cedar"
    };

    for (int i = 0; i < (int)words.size(); i++)
        ht.insert(words[i], i + 1);

    ht.printStats("After inserting " + to_string(words.size()) + " words");

    // Search
    cout << "\n-- Search --\n";
    try { cout << "  search(\"mango\")    = " << ht.search("mango")    << "\n"; }
    catch (exception& e) { cout << "  " << e.what() << "\n"; }
    try { cout << "  search(\"notaword\") = " << ht.search("notaword") << "\n"; }
    catch (exception& e) { cout << "  " << e.what() << "\n"; }

    // Remove
    cout << "\n-- Remove --\n";
    vector<string> toRemove = {"apple","banana","cherry","date","elderberry"};
    for (auto& k : toRemove)
        cout << "  remove(\"" << k << "\") -> " << (ht.remove(k) ? "ok" : "not found") << "\n";

    cout << "\n-- Verify removed --\n";
    for (auto& k : toRemove) {
        try   { ht.search(k); cout << "  \"" << k << "\" still there??\n"; }
        catch (...) { cout << "  \"" << k << "\" correctly gone\n"; }
    }
    ht.printStats("After removals");

    // --- Part 6: Three experiments ---
    cout << "\n\n--- Experiment 1: Random-ish strings ---\n";
    {
        HashTable e1;
        string charset = "abcdefghijklmnopqrstuvwxyz0123456789";
        srand(42);
        for (int i = 0; i < 150; i++) {
            string key = "";
            int len = 5 + rand() % 5;
            for (int j = 0; j < len; j++)
                key += charset[rand() % (int)charset.size()];
            e1.insert(key, i);
        }
        e1.printStats("Random strings (150 keys)");
    }

    cout << "\n--- Experiment 2: Sequential keys ---\n";
    {
        HashTable e2;
        for (int i = 1; i <= 150; i++)
            e2.insert("student" + to_string(i), i);
        e2.printStats("Sequential keys (150 keys)");
    }

    cout << "\n---  Experiment 3: Same-prefix keys ---\n";
    {
        HashTable e3;
        for (int i = 1; i <= 150; i++) {
            string num = to_string(i);
            while ((int)num.size() < 4) num = "0" + num;
            e3.insert("data_" + num, i);
        }
        e3.printStats("Same-prefix keys (150 keys)");
    }

    return 0;
}
```

## Explanation
Random Strings: When we test with random strings, then the hash-table distributes the keys evenly across the table. The characters in each key are very different; therefore, the hash function has a wide range of index values. Since there are a lot of index values, there are less number of collisons. This shows that when a there are keys which are different from each other, then the hash table performs well.

Sequential Keys: For the sequential keys (eg: 'student1') and the keys that are same-prefix (eg: data_0001), the keys start with same/similar characters. Though we assume that there will be more collisions, there are low number of collisions because the polynomial hash-function has the function which multiples by 31 every step (creating difference in numbers in the indices). There are also small bucket sizes.

