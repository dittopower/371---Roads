#ifndef _random_h
#define _random_h

/** INB371 - asgn2 Random.h - Damon Jones */

/// This class is based on the exercises included in Workshop 3. To ensure
/// that different random values are generated on successive runs, the
/// randomise() method is called by the constructor.
class Random {
public:

   /// Initialize the randomizer.
   Random();

   /// Generates a random integer number greater than or equal to low and less than high.
   int randomInteger(int low, int high);

   /// Generates a true false outcome based on the probability p.
   /// Calling randomChance(0.30) returns true 30% of the time.
   bool randomChance(double p);

    /// Generates a random real number greater than or equal to low and less than high.
    double randomReal(double low, double high);

private:

   /// Initializes the random-number generator so that its results are unpredictable.  If this
   /// function is not called the other functions will return the same values on each run.
   void randomize();
};

#endif // _random_h
