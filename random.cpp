#include <cstdlib>
#include <ctime>
#include "random.h"

/** INB371 - asgn2 Random.cpp - Damon Jones */

/// This class is based on the exercises included in Workshop 3. To ensure
/// that different random values are generated on successive runs, the
/// randomise() method is called by the constructor.


Random::Random() {
   randomize();
}

///Generates a random integer number greater than or equal to low and less than or equal to high.
int Random::randomInteger(int low, int high) {
   double d = double(rand()) / (double(RAND_MAX) + 1);
   int k = int(d * (high - low  + 1));
   return low + k;
}

/// Generates a true false outcome based on the probability p.
/// Calling randomChance(0.30) returns true 30% of the time.
bool Random::randomChance(double p) {
   return randomReal(0, 1) < p;
}

/// Generates a random real number greater than or equal to low and less than high.
double Random::randomReal(double low, double high) {
   double d = double(rand()) / (double(RAND_MAX) + 1);
   return low + d * (high - low);
}

///Initializes the random-number generator so that its results are unpredictable. If this function
/// is not called the other functions will return the same values on each run.
void Random::randomize() {
   srand(int(time(NULL)));
}
