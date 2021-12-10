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


Histogram dobaVProdukci("dobaVProdukci", 0, 1, 30);

std::queue<int> itemsInProduction;

class mStat: public Process {
   void Behavior() {
      Print("cas, v produkci, TODO var names here\n");
      while (1) {
         Print(static_cast<int>(Time));
         Print(",");
         Print(itemsInProduction.size());
         Print(",");
   //      std::cout << pocetSmenNepracDny + pocetSmenVikendy << ",";

      //   pocetSmenNepracDny = 0;
         Print("\n");

  //       Wait(STAT_PERIOD);
      }
   }
};

#endif
