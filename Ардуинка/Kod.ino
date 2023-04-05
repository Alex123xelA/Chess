struct Cell {
int row;
int col;
void setVal(int newRow, int newCol){
row = newRow;
col = newCol;
}
};

bool mas[8][12] = {
  {0,0, 1,1,1,1,1,1,1,1, 0,0},
  {0,0, 1,1,1,1,1,1,1,1, 0,0},
  {0,0, 0,0,0,0,0,0,0,0, 0,0},
  {0,0, 0,0,0,0,0,0,0,0, 0,0},
  {0,0, 0,0,0,0,0,0,0,0, 0,0},
  {0,0, 0,0,0,0,0,0,0,0, 0,0},
  {0,0, 1,1,1,1,1,1,1,1, 0,0},
  {0,0, 1,1,1,1,1,1,1,1 ,0,0}
};




//из calculatePath получаем массив с координатами

void setup() {
  // put your setup code here, to run once:
  Cell kor[10];
  kor[0].setVal(2,1);
  kor[1].setVal(2,2);   
  
  Serial.begin(9600);
  Lishnie(kor);
  for (int i = 0;i<9;i++){
    for(int u = 0;u<13;u++){
        Serial.print(mas[i][u]);                    
    }    
    Serial.println();  
}

}



//void Lishnie(/*Cell start,Cell end ,*/ Cell[] kor/*mas[8][12]*/ ){
void Lishnie( Cell kor[] ){  
  Cell start1;
//Serial.print(100);

  Cell end1;  
bool zn = 0;




for (int i = 0; i < int (sizeof(kor)*4/sizeof(Cell))-1;  i++){
  
start1 = kor[i];
/*Serial.print(start1.row);
Serial.print(" ");
Serial.println(start1.col);*/

end1 = kor[i+1];
/*Serial.print(end1.row);
Serial.print(" ");
Serial.println(end1.col);*/


if (mas[end1.col+2][end1.row]==1){
  //двигаем лишнее, двигаем фигуру хода
  if (end1.col!=  7+2   and end1.row!=  0   and zn ==0){if (mas[end1.col+2+1][end1.row+1]==0){
    zn = 1;
    mas[end1.col+2+1][end1.row+1]=1;
    mas[end1.col+2][end1.row]=0;}}

  if (end1.col!=  7+2   and end1.row!=  7   and zn ==0){if (mas[end1.col+2+1][end1.row+1]==0){
    zn = 1;
    mas[end1.col+2+1][end1.row+1]=1;
    mas[end1.col+2][end1.row]=0;}}

  if (end1.col!=  2   and end1.row!=  0   and zn ==0){if (mas[end1.col+2+1][end1.row+1]==0){
    zn = 1;
    mas[end1.col+2+1][end1.row+1]=1;
    mas[end1.col+2][end1.row]=0;}}

  if (end1.col!=  2   and end1.row!=  7   and zn ==0){if (mas[end1.col+2+1][end1.row+1]==0){
    zn = 1;
    mas[end1.col+2+1][end1.row+1]=1;
    mas[end1.col+2][end1.row]=0;}}
}
else{
  //двигаем фигуру хода
  mas[end1.col+2][end1.row] = 1;
  mas[start1.col+2][start1.row] = 0;
}

}

}




void loop() {
  // put your main code here, to run repeatedly:

}
