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
void Lishnie( Cell[] kor ){  
  
  bool zn = 0;

for (int i = 0; i < int (sizeof(kor)/sizeof(Cell));  i++){
Cell start = kor[i];
Cell end = kor[i+1];


if (mas[end.col+2][end.row]==1){
  //двигаем лишнее, двигаем фигуру хода
  if (end.col!=  7+2   and end.row!=  0   and zn ==0){if (mas[end.col+2+1][end.row+1]==0){
    zn = 1;
    mas[end.col+2+1][end.row+1]=1;
    mas[end.col+2][end.row]=0;}}

  if (end.col!=  7+2   and end.row!=  7   and zn ==0){if (mas[end.col+2+1][end.row+1]==0){
    zn = 1;
    mas[end.col+2+1][end.row+1]=1
    ;mas[end.col+2][end.row]=0;}}

  if (end.col!=  2   and end.row!=  0   and zn ==0){if (mas[end.col+2+1][end.row+1]==0){
    zn = 1;
    mas[end.col+2+1][end.row+1]=1;
    mas[end.col+2][end.row]=0;}}

  if (end.col!=  2   and end.row!=  7   and zn ==0){if (mas[end.col+2+1][end.row+1]==0){
    zn = 1;
    mas[end.col+2+1][end.row+1]=1;
    mas[end.col+2][end.row]=0;}}
}
else{
  //двигаем фигуру хода
  mas[end.col+2][end.row] = 1;
  mas[start.col+2][start.row] = 0;
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
