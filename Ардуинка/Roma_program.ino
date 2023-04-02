const int MAX_PATH_LENGTH = 64;
struct Cell {
int row;
int col;
};

int getAbs(int value) {
return value >= 0 ? value : -value;
}

int getSign(int value) {
return value >= 0 ? 1 : -1;
}

void calculatePath(Cell start, Cell end, Cell path[MAX_PATH_LENGTH], int& pathLength) {
int dx = getAbs(end.col - start.col);
int dy = getAbs(end.row - start.row);
int sx = getSign(end.col - start.col);
int sy = getSign(end.row - start.row);

pathLength = 0;

if (dx == 0 && dy == 0) {

path[pathLength++] = start;
return;
}

int err = dx - dy;
Cell cur = start;
while (true) {
path[pathLength++] = cur;
if (cur.row == end.row && cur.col == end.col) {
return;
}
int e2 = 2 * err;
if (e2 > -dy) {
err -= dy;
cur.col += sx;
}
if (e2 < dx) {
err += dx;
cur.row += sy;
}
}
}

void setup() {
Serial.begin(9600);

Cell start = {2, 1};
Cell end = {6, 5};
Cell path[MAX_PATH_LENGTH];
int pathLength;
calculatePath(start, end, path, pathLength);

for (int i = 0; i < pathLength; i++) {
Serial.print("(");
Serial.print(path[i].row);
Serial.print(",");
Serial.print(path[i].col);
Serial.print(") ");
}
Serial.println();
}
void loop() {
  // put your main code here, to run repeatedly:

}
