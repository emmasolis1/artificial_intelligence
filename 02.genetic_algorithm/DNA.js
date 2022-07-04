function Figura(tipo, x1, y1, x2, y2, fR, fG, fB, r,
  sR, sG, sB, lW) {

  //tipo de figura(circle,rectangle,line)  
  this.tipo = tipo;

  //coordenadas de la figura
  this.x1 = x1;
  this.y1 = y1;
  this.x2 = x2;
  this.y2 = y2;

  //color de relleno de la figura
  this.fR = fR;
  this.fG = fG;
  this.fB = fB;

  //radio del circulo
  this.r = r;

  //color del trazado de la figura
  this.sR = sR;
  this.sG = sG;
  this.sB = sB;

  //grosor del trazado de la figura
  this.lW = lW;
}

// Constructor (makes a random DNA)
class DNA {
  constructor(cantidadFiguras) {
    // The genetic sequence
    this.genes = [];
    this.fitness = 0;

    var tip = [];
    tip[0] = 'circle';
    tip[1] = 'rectangle';
    tip[2] = 'line';
    this.tipo = tip;

    for (let i = 0; i < cantidadFiguras; i++) {

      var t = Math.floor(Math.random() * 3);

      var x1 = Math.floor((Math.random() * 100) + 1);
      var y1 = Math.floor((Math.random() * 100) + 1);
      var x2 = Math.floor((Math.random() * 100) + 1);
      var y2 = Math.floor((Math.random() * 100) + 1);

      var fR = Math.floor((Math.random() * 255) + 1);
      var fG = Math.floor((Math.random() * 255) + 1);
      var fB = Math.floor((Math.random() * 255) + 1);

      var r = Math.floor((Math.random() * 20) + 1);

      var sR = Math.floor((Math.random() * 255) + 1);
      var sG = Math.floor((Math.random() * 255) + 1);
      var sB = Math.floor((Math.random() * 255) + 1);

      var lW = Math.floor((Math.random() * 5) + 1);

      this.genes[i] = new Figura(this.tipo[t], x1, y1, x2, y2, fR, fG, fB, r, sR, sG, sB, lW);
    }
  } //End of constructor(DNA)




  calcularAptitud(imageData1, imageData2) {
    var data1 = imageData1;
    var data2 = imageData2.data;
    var suma = 0;
    for (var i = 0; i < data1.length; i += 4) {
      suma += Math.pow((data1[i] - data2[i]), 2);
      suma += Math.pow((data1[i + 1] - data2[i + 1]), 2);
      suma += Math.pow((data1[i + 2] - data2[i + 2]), 2);
      suma += Math.pow(data1[i + 3] - data2[i + 3], 2);
    }
    this.fitness = Math.pow(suma, 1 / 2);
  }

  getAptitud() {
    return this.fitness;
  }


  //Cruza las figuras que tienen los padres
  cruzar(partner) {
    // A new child
    let child = new DNA(this.genes.length);

    let midpoint = Math.floor(Math.random(this.genes.length)); // Pick a midpoint

    // Half from one, half from the other
    for (let i = 0; i < this.genes.length; i++) {
      if (i > midpoint) child.genes[i] = this.genes[i];
      else child.genes[i] = partner.genes[i];
    }
    return child;
  }//End of crossover()

  

  // Muta las caracteristicas que tienen las figuras
  mutar(mutationRate) {
    var t;

    var x1;
    var y1;
    var x2;
    var y2;

    var fR;
    var fG;
    var fB;

    var r;

    var sR;
    var sG;
    var sB;

    var lW;

    for (let i = 0; i < this.genes.length; i++) {

      //Muta el tipo de figura
      if (Math.random(1) < mutationRate) {
        t = Math.floor(Math.random() * 3);
        this.genes[i].tipo = this.tipo[t];
      }

      //Muta coordenada x1
      if (Math.random(1) < mutationRate) {
        x1 = Math.floor((Math.random() * 100) + 1);
        this.genes[i].x1 = x1;
      }

      //Muta coordenada y1
      if (Math.random(1) < mutationRate) {
        y1 = Math.floor((Math.random() * 100) + 1);
        this.genes[i].y1 = y1;
      }

      //Muta coordenada x2
      if (Math.random(1) < mutationRate) {
        x2 = Math.floor((Math.random() * 100) + 1);
        this.genes[i].x2 = x2;
      }

      //Muta coordenada y2
      if (Math.random(1) < mutationRate) {
        y2 = Math.floor((Math.random() * 100) + 1);
        this.genes[i].y2 = y2;
      }

      //Muta color relleno Red
      if (Math.random(1) < mutationRate) {
        fR = Math.floor((Math.random() * 255) + 1);
        this.genes[i].fR = fR;
      }

      //Muta color relleno Green
      if (Math.random(1) < mutationRate) {
        fG = Math.floor((Math.random() * 255) + 1);
        this.genes[i].fG = fG;
      }

      //Muta color relleno Blue
      if (Math.random(1) < mutationRate) {
        fB = Math.floor((Math.random() * 255) + 1);
        this.genes[i].fB = fB;
      }

      //Muta radio
      if (Math.random(1) < mutationRate) {
        r = Math.floor((Math.random() * 20) + 1);
        this.genes[i].r = r;
      }

      //Muta color trazado Red
      if (Math.random(1) < mutationRate) {
        sR = Math.floor((Math.random() * 255) + 1);
        this.genes[i].sR = sR;
      }

      //Muta color trazado Green
      if (Math.random(1) < mutationRate) {
        sG = Math.floor((Math.random() * 255) + 1);
        this.genes[i].sG = sG;
      }

      //Muta color trazado Blue
      if (Math.random(1) < mutationRate) {
        sB = Math.floor((Math.random() * 255) + 1);
        this.genes[i].sB = sB;
      }

      //Muta grosor trazado
      if (Math.random(1) < mutationRate) {
        lW = Math.floor((Math.random() * 5) + 1);
        this.genes[i].lW = lW;
      }

    }
  }//End of mutar()





}

