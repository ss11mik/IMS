 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#include <simlib.h>

//TODO
#define STAT_PERIOD 200


class mStat: public Process {
   void Behavior() {
      Print("cas, TODO var names here\n");
      while (1) {
         Print(static_cast<int>(Time));
         Print(",");
   //      std::cout << pocetSmenNepracDny + pocetSmenVikendy << ",";

      //   pocetSmenNepracDny = 0;
         Print("\n");

         Wait(STAT_PERIOD);
      }
   }
};

class ClearStat: public Process {
   void Behavior() {

   }
};
