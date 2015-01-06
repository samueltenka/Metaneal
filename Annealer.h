#include <random>

#define ENERGY_RANGE 1000



const std::default_random_engine RANDOM_GENERATOR;
const std::uniform_int_distribution<int> UNIF_DISTRIBUTION(0,ENERGY_RANGE-1);
int get_random() {return UNIF_DISTRIBUTION(RANDOM_GENERATOR);}


class Mutation {
public:
   double energy_change;
   // have other information?
};

class Crystal {
public:
   virtual Mutation mutate_preview() const; // INSERT TEMPERATURE-DEPENDENCE?
   virtual void enact_mutation(Mutation M);
};


class Annealer {
private:
   double acceptance_curve[ENERGY_RANGE];
   //double temperature_schedule[ENERGY_RANGE];

   double temperature;
   Crystal* mine;
public:
   Annealer(Crystal* to_be_mine) {
      mine = to_be_mine;
   }

   bool does_accept(int energy_diff) {
      double random = (static_cast<double>(get_random()))/(ENERGY_RANGE); // in [0, 1)
      return random < acceptance_curve[energy_diff];
   }

   void step() {
      Mutation M = mine->mutate_preview();
      if(does_accept(M.energy_change)) {mine->enact_mutation(M);}
   }
};
