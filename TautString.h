#include "Annealer.h"
#define CRYSTAL_SIZE 1000

#define MAX(A, B) ((A)>(B)?(A):(B))
#define MIN(A, B) ((A)<(B)?(A):(B))


const std::default_random_engine RANDOM_GENERATOR_LOC;
const std::uniform_int_distribution<int> UNIF_DISTRIBUTION_LOC(0,CRYSTAL_SIZE-1);
int get_random_loc() {return UNIF_DISTRIBUTION_LOC(RANDOM_GENERATOR_LOC);}



class StringMutation: public Mutation {
public:
   double energy_diff;
   int location;
   int amount;
};

class TautString: public Crystal {
private:
   int crystal[CRYSTAL_SIZE];
public:
   Mutation mutate_preview() const {
      StringMutation M;
      M.location = get_random_loc();
      M.new_height = crystal[M.location] + get_random();

      int left=crystal[MAX(0, M.location-1)], //   (M.location-1)%CRYSTAL_SIZE
          right=crystal[MIN(CRYSTAL_SIZE, M.location-1)]; // (M.location+1)%CRYSTAL_SIZE
      M.energy_diff =  
   }
   void enact_mutation(StringMutation M) {
      crystal[M.location] += M.amount;
      crystal[M.location] %= ENERGY_RANGE;
   }
};
