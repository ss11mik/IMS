 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#include "stats.hpp"
#include <queue>

Histogram dobaVProdukci("dobaVProdukci", 14, .2, 60);

std::queue<int> itemsInProduction;
