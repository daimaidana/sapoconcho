// programa básico para Sapoconcho con los movimientos como subrutinas y no como librerías

#define AIA 11 // HIGH >> left backward
#define AIB 6 // HIGH >> left forward
#define BIA 9 // HIGH >> right forward
#define BIB 10 // HIGH >> right backwards

void setup() {

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
}

void loop() {

      forward(128,128,1000); // adelante (velocidad rueda izquierda, vel rueda derecha, tiempo)
      reverse(128,128,1000); // adelante (velocidad rueda izquierda, vel rueda derecha, tiempo)
      rotate(128,128,1000); // gira a la derecha (vel rueda izq, del rueda der, tiempo)
      rotate(128,128,-1000); // gira a la izquierda (vel rueda izq, del rueda der, tiempo)
      brake(1000); // frena (tiempo)
      drive(128,-128,1000); // desplazamiento general (vel rueda izq, del rueda der, tiempo) vel pos o neg
      
  }
  
  tone(13,1500,50);

}

void forward(int l, int r, int t)
{
  analogWrite(AIA,0);
  analogWrite(AIB,l);
  analogWrite(BIA,0);
  analogWrite(BIB,r);
  delay(t);
}

void reverse(int l, int r, int t)
{
  analogWrite(AIA,l);
  analogWrite(AIB,0);
  analogWrite(BIA,r);
  analogWrite(BIB,0);
  delay(t);
}

void rotate(int l, int r, int t)
{
  if (t>0)
  {
    analogWrite(AIA,l);
    analogWrite(AIB,0);
    analogWrite(BIA,r);
    analogWrite(BIB,0);
  }
  else
  {
    analogWrite(AIA,0);
    analogWrite(AIB,l);
    analogWrite(BIA,0);
    analogWrite(BIB,r);
  }
  delay(abs(t));
}

void brake(int t)
{
  analogWrite(AIA,0);
  analogWrite(AIB,0);
  analogWrite(BIA,0);
  analogWrite(BIB,0);
  delay(t);
}

void drive(int l, int r, int t)
{
  if (l>0)
  {
    analogWrite(AIA,0);
    analogWrite(AIB,l);
  } else {
    analogWrite(AIA,-l);
    analogWrite(AIB,0);
  }
  
  if (r>0)
  {
    analogWrite(BIA,r);
    analogWrite(BIB,0);    
  } else {
    analogWrite(BIA,0);
    analogWrite(BIB,-r);
  }
  
  delay(t);
}
