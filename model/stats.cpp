 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#ifndef STATS_H
#define STATS_H

#include <queue>
#include <simlib.h>


Histogram dobaVProdukci("dobaVProdukci", 14, .2, 60);

std::queue<int> itemsInProduction;


#endif
