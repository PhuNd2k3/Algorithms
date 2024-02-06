#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Item
{
    int index, width, length;
};

struct Truck
{
    int index, width, length, cost;
};

bool compareItems(const Item &a, const Item &b)
{
    return a.width * a.length > b.width * b.length;
}

bool compareTrucks(const Truck &a, const Truck &b)
{
    return a.cost < b.cost;
}

void loadItemsIntoTrucks(int N, int K, vector<Item> &items, vector<Truck> &trucks)
{
    sort(items.begin(), items.end(), compareItems);
    sort(trucks.begin(), trucks.end(), compareTrucks);

    vector<tuple<int, int, int, int>> placements;
    vector<pair<int, int>> remainingSpace(K, {0, 0});

    for (int itemIndex = 0; itemIndex < N; ++itemIndex)
    {
        int itemW = items[itemIndex].width;
        int itemL = items[itemIndex].length;

        if (itemL > itemW)
        {
            swap(itemW, itemL);
        }

        int bestTruck = -1;
        tuple<int, int, int> bestPosition;

        for (int truckIndex = 0; truckIndex < K; ++truckIndex)
        {
            int truckW = trucks[truckIndex].width;
            int truckL = trucks[truckIndex].length;

            for (int rotation = 0; rotation < 2; ++rotation)
            {
                if (rotation == 1)
                {
                    swap(itemW, itemL);
                }

                if (itemW <= truckW && itemL <= truckL)
                {
                    bool overlap = false;
                    for (const auto &placedItem : placements)
                    {
                        int placedT, placedX, placedY, placedO;
                        tie(placedT, placedX, placedY, placedO) = placedItem;

                        if (placedT == truckIndex && placedO == 0)
                        {
                            int placedW = items[placedT].width;
                            int placedL = items[placedT].length;

                            if (placedX <= itemW + placedX && itemW + placedX <= placedX + placedW &&
                                placedY <= itemL + placedY && itemL + placedY <= placedY + placedL)
                            {
                                overlap = true;
                                break;
                            }
                        }
                    }

                    if (!overlap)
                    {
                        bestTruck = truckIndex;
                        bestPosition = make_tuple(remainingSpace[truckIndex].first, remainingSpace[truckIndex].second, rotation);
                        break;
                    }
                }
            }

            if (bestTruck != -1)
            {
                remainingSpace[bestTruck].first -= get<0>(bestPosition);
                remainingSpace[bestTruck].second -= get<1>(bestPosition);
                placements.emplace_back(bestTruck, get<0>(bestPosition), get<1>(bestPosition), get<2>(bestPosition));
                break;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int t, x, y, o;
        tie(t, x, y, o) = placements[i];
        cout << items[t].index << " " << t + 1 << " " << x << " " << y << " " << o << "\n";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int N, K;
    cin >> N >> K;

    vector<Item> items(N);
    for (int i = 0; i < N; ++i)
    {
        items[i].index = i;
        cin >> items[i].width >> items[i].length;
    }

    vector<Truck> trucks(K);
    for (int k = 0; k < K; ++k)
    {
        trucks[k].index = k;
        cin >> trucks[k].width >> trucks[k].length >> trucks[k].cost;
    }

    loadItemsIntoTrucks(N, K, items, trucks);

    return 0;
}
