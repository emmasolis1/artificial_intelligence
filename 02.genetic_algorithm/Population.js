// A class to describe a population of virtual organisms
// In this case, each organism is just an instance of a DNA object

class Population {
  constructor(target, mutationRate, popMax, cantidadFiguras) {
    this.population = []; // Array to hold the current population
    this.matingPool = []; // ArrayList which we will use for our "mating pool"
    this.generations = 0; // Number of generations
    this.finished = false; // Are we finished evolving?
    this.target = target.data; // pixels data
    this.mutationRate = mutationRate; // Mutation rate
    this.perfectScore = 1;
    this.cantidadFiguras = cantidadFiguras;

    this.best = "";

    for (let i = 0; i < popMax; i++) {
      this.population[i] = new DNA(this.cantidadFiguras);
    }
  }// End of constructor(Population)


  /*  
    //Invoca al metodo calcularAptitud dentro de cada individuo 
    //de la poblacion
      calcularAptitud() {
      for (let i = 0; i < this.population.length; i++) {
        this.population[i].calcularAptitud(this.target);
      }
    }
  */





  seleccion() {
    // Clear the ArrayList
    this.matingPool = [];

    let maxFitness = 0;
    for (let i = 0; i < this.population.length; i++) {
      if (this.population[i].fitness > maxFitness) {
        maxFitness = this.population[i].fitness;
      }
    }

    let minFitness = Number.MAX_VALUE;
    for (let i = 0; i < this.population.length; i++) {
      if (this.population[i].fitness < minFitness) {
        minFitness = this.population[i].fitness;
      }
    }

    // Based on fitness, each member will get added to the mating pool a certain number of times
    // a higher fitness = more entries to mating pool = more likely to be picked as a parent
    // a lower fitness = fewer entries to mating pool = less likely to be picked as a parent
    for (let i = 0; i < this.population.length; i++) {
      let fitness = (this.population[i].fitness - minFitness) / (maxFitness - minFitness);
      let n = Math.floor(fitness * 100) + 1; // Arbitrary multiplier, we can also use monte carlo method
      for (let j = 0; j < n; j++) {
        this.matingPool.push(this.population[i]);
      }
    }

    // Refill the population with children from the mating pool
    console.log("GENERACION");
    console.log(this.generations);

    for (let i = 0; i < this.population.length; i++) {
      let a = Math.floor(Math.random() * this.matingPool.length);
      let b = Math.floor(Math.random() * this.matingPool.length);
      let partnerA = this.matingPool[a];
      let partnerB = this.matingPool[b];

      let child = partnerA.cruzar(partnerB);
      child.mutar(this.mutationRate);
      this.population[i] = child;
    }
    this.generations++;
  }//End of seleccion()






  getBest() {
    return this.best;
  }






  // Compute the current "most fit" member of the population
  evaluate() {
    let worldrecord = 0.0;
    let index = 0;
    for (let i = 0; i < this.population.length; i++) {
      if (this.population[i].fitness > worldrecord) {
        index = i;
        worldrecord = this.population[i].fitness;
      }
    }

    this.best = this.population[index].getPhrase();
    if (worldrecord === this.perfectScore) {
      this.finished = true;
    }
  } //End of evaluate





  isFinished() {
    return this.finished;
  }




  getGenerations() {
    return this.generations;
  }




}//End of class population