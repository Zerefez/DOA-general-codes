#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <array>
#include <climits>

using namespace std;

struct flight_location {
    int price = INT_MAX; // Initialize price to avoid uninitialized variable warning
    vector<int> path; // Gemmer den rute, der førte til destinationen
};

flight_location flight_find_cheapest(int n, vector<array<int, 5>>& flights, int src, int dst, int stops, unordered_map<int, int>& came_from) {
    // Graf repræsentation (adjacency list)
    unordered_map<int, vector<array<int, 4>>> graph; // node -> {to, price, depart, arrive}
    for (const auto& flight : flights) {
        graph[flight[0]].push_back({ flight[1], flight[2], flight[3], flight[4] });
    }

    // Min-heap: {pris, nærværende lufthavn, stops tilbage, ankomsttid}
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({ 0, src, stops + 1, 0 }); // Start med pris 0, startlufthavn, maks stops + 1, og 0 som ankomsttid

    // Distance-array til at gemme billigste pris og resterende stops
    vector<vector<int>> min_price(n, vector<int>(stops + 2, INT_MAX));
    min_price[src][stops + 1] = 0;

    cout << "Initialisering fuldført. Starter søgning..." << endl;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int current_price = current[0];
        int current_airport = current[1];
        int stops_left = current[2];
        int arrival_time = current[3];

        cout << "Behandler lufthavn " << current_airport << " med pris " << current_price << ", stops tilbage: " << stops_left << endl;

        // Hvis vi har nået destinationen, returner billigste pris og rute
        if (current_airport == dst) {
            cout << "Destination " << dst << " nået med pris " << current_price << endl;
            flight_location result;
            result.price = current_price;

            // Rekonstruer stien ved hjælp af came_from
            int node = dst;
            while (came_from.count(node)) {
                result.path.push_back(node);
                node = came_from[node];
            }
            result.path.push_back(src);
            reverse(result.path.begin(), result.path.end());
            return result;
        }

        // Hvis vi ikke har flere stops tilbage, kan vi ikke fortsætte
        if (stops_left == 0) {
            cout << "Ingen stops tilbage ved lufthavn " << current_airport << endl;
            continue;
        }

        // Undersøg alle naboer
        for (const auto& neighbor : graph[current_airport]) {
            int next_airport = neighbor[0];
            int price = neighbor[1];
            int depart_time = neighbor[2];
            int arrive_time = neighbor[3];

            if (depart_time >= arrival_time) { // Kun fortsæt, hvis afgangstidspunktet er efter ankomst
                int new_price = current_price + price;
                cout << "Overvejer fly til " << next_airport << " med pris " << new_price << ", afgang: " << depart_time << ", ankomst: " << arrive_time << endl;
                if (new_price < min_price[next_airport][stops_left - 1]) {
                    min_price[next_airport][stops_left - 1] = new_price;
                    came_from[next_airport] = current_airport; // Opdater sti
                    cout << "Opdaterer rute til " << next_airport << " med ny pris " << new_price << endl;
                    pq.push({ new_price, next_airport, stops_left - 1, arrive_time });
                }
                else {
                    cout << "Fly til " << next_airport << "ignoreret, da det ikke er billigere." << endl;
                }
            }
            else {
                cout << "Fly til " << next_airport << " ignoreret pga. tidskonflikt." << endl;
            }
        }
    }

    // Hvis vi aldrig nåede destinationen
    cout << "Ingen rute fundet til destination " << dst << " med de givne restriktioner." << endl;
    return { INT_MAX, {} };
}

int main() {
    vector<array<int, 5>> flights = {
        {0, 1, 500, 0, 1},
        {0, 3, 200, 0, 1},
        {3, 1, 200, 2, 3},
        {1, 4, 100, 4, 5},
        {1, 2, 500, 4, 5},
        {4, 2, 100, 6, 7}
    };

    unordered_map<int, int> came_from;
    int n = 5;
    int src = 0;
    int dst = 2;
    int stops = 2;

    flight_location result = flight_find_cheapest(n, flights, src, dst, stops, came_from);

    if (result.price != INT_MAX) {
        cout << "Billigste pris: " << result.price << "\nRute: ";
        for (int airport : result.path) {
            cout << airport << " ";
        }
        cout << endl;
    }
    else {
        cout << "Ingen rute fundet med de givne restriktioner." << endl;
    }

    return 0;
}
