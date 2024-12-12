struct Point {
    int x;
    int y;
// Completar
};
void draw_figure ( Point & p ) {
    p.draw();
// Completar
}


struct Line {
    Point _inicio ;
    Point _final ;
    Line ( int x1 , int y1 , int x2 , int y2 ) {
        _inicio . x = x1 ;
        _inicio . y = y1 ;
        _final . x = x2 ;
        _final . y = y2 ;
    }
    void draw () {
        cout <<" Linea : ␣ " ;
        cout << _inicio ;
        cout << " -------" ;
        cout << _final ;
        cout << endl ;
    }
};
struct LineAdapter{

};
int main () {
    Line obj1 (2 ,2 ,5 ,6) ;
    LineAdapter adapter ( obj1 ) ;
    draw_figure ( adapter ) ;
// Resultado :
// Linea : P (2 ,2) -------P (5 ,6)
    return 0;
}
