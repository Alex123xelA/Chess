struct Cell {
int row; //y
int col; //x
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





//void Lishnie(/*Cell start,Cell end ,*/ Cell[] kor/*mas[8][12]*/ ){
void Lishnie( Cell kor[] ){  
  
  bool zn = 0;

for (int i = 0; i < int (sizeof(kor)/sizeof(Cell));  i++){
Cell start1 = kor[i];
Cell end1 = kor[i+1];


if (mas[end1.col+2][end1.row]==1){
  //двигаем лишнее, двигаем фигуру хода
  if (end1.col!=  7+2   and end1.row!=  0   and zn ==0){if (mas[end1.col+2+1][end1.row+1]==0){
    zn = 1;
    mas[end1.col+2+1][end1.row+1]=1;
    mas[end1.col+2][end1.row]=0;}}

  if (end1.col!=  7+2   and end1.row!=  7   and zn ==0){if (mas[end1.col+2+1][end1.row+1]==0){
    zn = 1;
    mas[end1.col+2+1][end1.row+1]=1
    ;mas[end1.col+2][end1.row]=0;}}

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


void setup() {
  // put your setup code here, to run once:
  Cell kor = {(2,1),(6,5)};
  Serial.begin(9600);
  Lishnie(/*{2,1},{6,5},*/Cell[] {(2,1),(6,5)});
  Serial.print(mas[8][12]);
}

void loop() {
  // put your main code here, to run repeatedly:

}
