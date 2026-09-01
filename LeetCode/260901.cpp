char A[400];
int dir[5]={0, 1, 0, -1, 0};
int bestE[400][1024];
using int3=tuple<short, short, short>;
constexpr int N=400*1024*51;
int3 q[N];
int front, back;
class Solution {
public:
    inline static int idx(int i, int j, int c){ return i*c+j; }
    inline static bool isOutside(int i, int j, int r, int c){
        return i<0 || i>=r || j<0 || j>=c ;
    }
    static int minMoves(vector<string>& classroom, int energy) {
        const int r=classroom.size(), c=classroom[0].size(), rc=r*c;
        unsigned LMask=0, Lidx=0;
        int S0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                char ch=classroom[i][j];
                int key=idx(i, j, c);
                if (ch=='L') A[key]=Lidx++;
                else {
                    A[key]=ch;
                    if (ch=='S') S0=key;
                }
            }
        }
        LMask=(1<<Lidx)-1;
        for(int i=0; i<rc; i++)// reset bestE
            memset(bestE[i], -1, sizeof(int)*(1<<Lidx));

        front=back=0;
        q[back++]={S0, 0, energy};
        bestE[S0][0]=energy;
        for(int step=0; front<back; step++){
            int qz=back-front;
            while(qz--){
                auto [ij, mask, en]=q[front++];
        
                if (mask==LMask) return step;
                if (en==0) continue;
                 auto [i, j]=div(ij, c);
                for(int a=0; a<4; a++){
                    int s=i+dir[a], t=j+dir[a+1], k=idx(s, t, c);
                    if (isOutside(s, t, r, c) || A[k]=='X') continue;
                    int  mask2=mask, en2;
                    if (A[k]<Lidx) mask2|=(1<<A[k]);
                    en2=(A[k]=='R')?energy:en-1;
                    if (en2>bestE[k][mask2]){
                        bestE[k][mask2]=en2;
                        q[back++]={k, mask2, en2};
                    }
                }
            }
        }
        return -1;
    }
};
