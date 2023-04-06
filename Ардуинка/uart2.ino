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
  Cell kor[7];
  kor[0].setVal(0,0);
  kor[1].setVal(0,1);
  kor[2].setVal(0,2);
  kor[3].setVal(0,3);
  kor[4].setVal(0,5);
  kor[5].setVal(0,6);
  kor[6].setVal(0,7);
  kor[7].setVal(0,8); 

  int lk = sizeof(kor)/sizeof(Cell);
  
  Serial.begin(9600);
  Lishnie(kor,lk);
  for (int i = 0;i<9;i++){
    for(int u = 0;u<13;u++){
        Serial.print(mas[i][u]);                    
    }    
    Serial.println();  
}
Serial.println(sizeof(kor));
Serial.println(sizeof(Cell));
}



//void Lishnie(/*Cell start,Cell end ,*/ Cell[] kor/*mas[8][12]*/ ){
void Lishnie( Cell kor[] , int lk){  
  Cell start1;
  Cell end1;
    
bool zn = 0;

Cell per[lk][2];



for (int i = 0;i<lk;  i++){
zn = 0;
  
start1 = kor[i];
Serial.print(start1.row);
Serial.print(" ");
Serial.println(start1.col);

end1 = kor[i+1];
Serial.print(end1.row);
Serial.print(" ");
Serial.println(end1.col);


/*if (mas[end1.row+2][end1.col]==1){
  //двигаем лишнее, двигаем фигуру хода
  if (end1.row!=  7+2   and end1.col!=  0   and zn ==0){if (mas[end1.row+2+1][end1.col+1]==0){
    zn = 1;
    mas[end1.row+2+1][end1.col+1]=1;
    mas[end1.row+2][end1.col]=0;
    mas[start1.row+2][start1.col] = 0;}}

  if (end1.row!=  7+2   and end1.col!=  7   and zn ==0){if (mas[end1.row+2+1][end1.col+1]==0){
    zn = 1;
    mas[end1.row+2+1][end1.col+1]=1;
    mas[end1.row+2][end1.col]=0;
    mas[start1.row+2][start1.col] = 0;}}

  if (end1.row!=  2   and end1.col!=  0   and zn ==0){if (mas[end1.row+2+1][end1.col+1]==0){
    zn = 1;
    mas[end1.row+2+1][end1.col+1]=1;
    mas[end1.row+2][end1.col]=0;
    mas[start1.row+2][start1.col] = 0;}}

  if (end1.row!=  2   and end1.col!=  7   and zn ==0){if (mas[end1.row+2+1][end1.col+1]==0){
    zn = 1;
    mas[end1.row+2+1][end1.col+1]=1;
    mas[end1.row+2][end1.col]=0;
    mas[start1.row+2][start1.col] = 0;}}
}
else{
  //двигаем фигуру хода
  mas[end1.row+2][end1.col] = 1;
  mas[start1.row+2][start1.col] = 0;
}*/

if (mas[end1.col][end1.row]==1){
  if (end1.row==7 and end1.col==0){
    if (mas[end1.row-1+2][end1.col]==0 and zn==0){zn=1;per[i][1].setVal(end1.row+2,end1.col);per[i][2].setVal(end1.row-1+2,end1.col);
    }
    if
    (mas[end1.row+2][end1.col+1]==0 and zn==0){zn=1;per[i][1].setVal(end1.row+2,end1.col);per[i][2].setVal(end1.row+2,end1.col+1);
    }
    if (mas[8][1]==0 and zn==0){zn=1;per[i][1].setVal(9,0);per[i][2].setVal(8,1);}
    }
  if (end1.row==7 and end1.col==7){
    if (mas[9][6]==0 and zn==0){zn=1;per[i][1].setVal(9,7);per[i][2].setVal(9,6);}
    if (mas[8][7]==0 and zn==0){zn=1;per[i][1].setVal(9,7);per[i][2].setVal(8,7);}
    if (mas[8][6]==0 and zn==0){zn=1;per[i][1].setVal(9,7);per[i][2].setVal(8,6);}
  }
  if (end1.row==0 and end1.col==7){
    if (mas[3][7]==0 and zn==0){zn=1;per[i][1].setVal(2,7);per[i][2].setVal(3,7);}
    if (mas[2][6]==0 and zn==0){zn=1;per[i][1].setVal(2,7);per[i][2].setVal(2,6);}
    if (mas[3][6]==0 and zn==0){zn=1;per[i][1].setVal(2,7);per[i][2].setVal(8,7);}
  }
  if (end1.row==0 and end1.col==0){
    if (mas[2][1]==0 and zn==0){zn=1;per[i][1].setVal(2,0);per[i][2].setVal(2,1);}
    if (mas[3][0]==0 and zn==0){zn=1;per[i][1].setVal(2,0);per[i][2].setVal(3,0);}
    if (mas[3][1]==0 and zn==0){zn=1;per[i][1].setVal(2,0);per[i][2].setVal(8,7);}
  }
  if (end1.col==0){
    if (mas[end1.col][end1.row+2+1]==0 and zn==0){zn=1;}
    if (mas[end1.col][end1.row+2-1]==0 and zn==0){zn=1;}
    if (mas[end1.col+1][end1.row+2]==0 and zn==0){zn=1;}
    if (mas[end1.col+1][end1.row+2+1]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2-1]==0 and zn==0){zn=1;}
    }
  if (end1.col==7){
    if (mas[end1.col][end1.row+2-1]==0 and zn==0){zn=1;}
    if (mas[end1.col][end1.row+2+1]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2-1]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2+1]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2]==0 and zn==0){zn=1;}
    }
  if (end1.row==0){
    if (mas[end1.col+1][end1.row+2]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2]==0 and zn==0){zn=1;}
    if (mas[end1.col+1][end1.row+2+1]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2+1]==0 and zn==0){zn=1;}
    if (mas[end1.col][end1.row+2+1]==0 and zn==0){zn=1;}
    }
  if (end1.row==7){
    if (mas[end1.col+1][end1.row+2]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2]==0 and zn==0){zn=1;}
    if (mas[end1.col+1][end1.row+2-1]==0 and zn==0){zn=1;}
    if (mas[end1.col-1][end1.row+2-1]==0 and zn==0){zn=1;}
    if (mas[end1.col][end1.row+2-1]==0 and zn==0){zn=1;}
    }
  if (zn==0){
    if(mas[end1.col+1][end1.row+2]==0){zn=1;}
    if(mas[end1.col+1][end1.row+2+1]==0){zn=1;}
    if(mas[end1.col+1][end1.row+2-1]==0){zn=1;}
    if(mas[end1.col-1][end1.row+2]==0){zn=1;}
    if(mas[end1.col-1][end1.row+2-1]==0){zn=1;}
    if(mas[end1.col-1][end1.row+2+1]==0){zn=1;}
    if(mas[end1.col][end1.row+2+1]==0){zn=1;}
    if(mas[end1.col][end1.row+2-1]==0){zn=1;}
    }
}
else{
  mas[start1.col][start1.row]=0;
  mas[end1.col][end1.row]=1;   }

  
for (int i = 0;i<9;i++){
    for(int u = 0;u<13;u++){
        Serial.print(mas[i][u]);                    
    }    
    Serial.println();  
}

}

}




void loop() {
  // put your main code here, to run repeatedly:

}
