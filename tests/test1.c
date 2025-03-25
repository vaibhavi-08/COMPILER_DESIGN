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
    //game mygame(x,y);
    game* alpha=new game(x,y);
}