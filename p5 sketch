var xspacing = 16;    // Distance between each horizontal location
var w;                // Width of entire wave
var theta = 0.0;      // Start angle at 0
var amplitude = 50.0; // Height of wave
var period = 500.0;   // How many pixels before the wave repeats
var dx;               // Value for incrementing x
var yvalues;  // Using an array to store height values for the wave

var f=[];
var numberFish= 67;
var b=[];
var numberBubbles=400;

function setup() {
  createCanvas(displayWidth, displayHeight);
  w = width+16;
  dx = (TWO_PI / period) * xspacing;
  yvalues = new Array(floor(w/xspacing));
	
	  //adds 50 fish to the array
  for (var i=0; i<numberFish; i++) {
      f.push(new Fish());
  }
  
  //adds 20 bubbles to the array
  for(var g=0; g<numberBubbles; g++){
       b.push(new Bubble()); 
    
  }
}

function draw() {
  background(0,215,225);
	
	     for (var g=0; g<b.length; g++){
       b[g].move();
       b[g].draw();
   
} 
 
   //it goes through every fish in the array and calls its draw function and swim function
   for (var i=0; i<f.length; i++){
       f[i].swim();
       f[i].draw();
  }
	
  calcWave();
  renderWave(); 
	sun();
}

function calcWave() {
  // Increment theta (try different values for 
  // 'angular velocity' here)
  theta += 0.02;

  // For every x value, calculate a y value with sine function
  var x = theta;
  for (var i = 0; i < yvalues.length; i++) {
    yvalues[i] = sin(x)*amplitude;
    x+=dx;
  }
}

function renderWave() {
  noStroke();
  fill(255);
  // A simple way to draw the wave with an ellipse at each location
  for (var x = 0; x < yvalues.length; x++) {
    ellipse(x*xspacing, height/2+yvalues[x], 16, 16);
  }
}

function sun(){
  fill(255,255,0);
  ellipse(150,150,100,100);
}

function Fish(){
  this.x= random (0,width);
  this.y=random (0,height);
  this.speed=random(0.5,2);
  //determines whether it moves right or left
  if (random (-1,1) <0) { 
  //if it moves left speed will be a negative number  
  this.speed *= -1;}
  this.size=random (10,20);
  this.r=random (0,255);
  this.g=random (0,255);
  this.b=random (0,255);
}
    
Fish.prototype.constructor=Fish;
Fish.prototype.draw=function(){
  fill (this.r, this.g, this.b);
  
  //push says i am going to move the grid remember where it is right now
  push();
  
  //translate moves 0,0 point to where we want it to be
  translate(this.x,this.y);
  if(this.speed<0){
     //moving left
    
    //turns the grib upside down if the fish is moving left
    rotate(PI);
  
  }
  triangle (0, 0, 0, -this.size, this.size,
            -this.size/2);
  ellipse (this.size*2.5, -this.size/2, this.size*2.7, 
           this.size);
  
    //pop says i am done to moving the grid go back to where it was before 
     pop();
  
};

Fish.prototype.swim = function(){
  this.x += this.speed;
  if (this.x<=-this.size*4 || this.x >=width+this.size*4) {
       this.speed *= -1;
    
  }
};


function Bubble(){
   this.x=random (0,width);
   this.size= random (3,15);
   this.y=height+random(this.size*2,this.size*20);
   this.speed= 2;
  
}

Bubble.prototype.constructor=Bubble;
Bubble.prototype.move= function (){
       this.y-=this.speed;
  if (this.y<-this.size*2){
   this.y=height+random(this.size*2,this.size*20);
  } 
};

Bubble.prototype.draw=function(){
       fill(255,255,255,75);
      ellipse(this.x,this.y,this.size,this.size);
        
};
