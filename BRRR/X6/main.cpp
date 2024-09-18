#include "Map.h"

int main()
{

    Map<string, int> map;

    map.insert("John", 25);
    map.insert("Khaled", 30);
    map.insert("Ibo", 35);

    cout << "Initial map:" << endl;
    map.display();

    cout << "\nAccessing 'John' using operator[]: " << map["John"] << endl;

    map["John"] = 999;
    cout << "\nUpdated 'John' value:" << endl;
    map.display();

    cout << "\nInserting a new key using operator[]:" << endl;
    map["LOL"] = 100;
    map.display();

    cout << "\nContains 'Yeet'? " << (map.contains("YEET") ? "Yes" : "No") << endl;
    cout << "Contains 'Khaled'? " << (map.contains("Khaled") ? "Yes" : "No") << endl;

    cout << "\nRemoving 'LOL':" << endl;
    map.remove("LOL");
    map.display();

    try {
        map.remove("LOL");
    }
    catch (const exception& e) {
        cout << "\nException: " << e.what() << endl;
    }

    return 0;
}
