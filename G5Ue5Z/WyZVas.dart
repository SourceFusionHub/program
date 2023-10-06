double calculatePolygonArea(List<List<double>> vertices) {
  int n = vertices.length;
  double area = 0;

  for (int i = 0; i < n; i++) {
    double xi = vertices[i][0];
    double yi = vertices[i][1];
    double xi1 = vertices[(i + 1) % n][0];
    double yi1 = vertices[(i + 1) % n][1];

    area += (xi * yi1 - xi1 * yi);
  }

  area = 0.5 * area.abs();
  return area;
}

void main() {
  List<List<double>> vertices = [
    [0, 0],
    [4, 0],
    [4, 3],
    [0, 3]
  ];

  double area = calculatePolygonArea(vertices);
  print('The area of the polygon is $area square units.');
}
