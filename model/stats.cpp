#include "stats.hpp"
#include <queue>

Histogram dobaVProdukci("dobaVProdukci", 14, .2, 60);

std::queue<int> itemsInProduction;
