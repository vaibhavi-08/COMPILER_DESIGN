class game{
    public:
    int z;
    int y;
    private:
    game(int k,int j){
        z=k;
        y=j;
    }
};
class football : public game{
    int z;
    int g;
};
int main(){
    int x;
    int y;
    class football *f1= new game(x,y);
    class game *g1= new game();
    class game g2={x,y};
    class game g3;

}