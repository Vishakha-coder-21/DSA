class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) a[i]={nums[i],i};
        sort(a.begin(),a.end());

        vector<int> pos(n);
        for(int i=0;i<n;i++) pos[a[i].second]=i;

        vector<int> comp(n);
        int c=0;
        for(int i=1;i<n;i++){
            if(a[i].first-a[i-1].first>maxDiff) c++;
            comp[i]=c;
        }

        vector<int> nxt(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n&&a[j+1].first-a[i].first<=maxDiff) j++;
            nxt[i]=j;
        }

        const int LG=17;
        vector<vector<int>> up(LG,vector<int>(n));
        up[0]=nxt;
        for(int k=1;k<LG;k++)
            for(int i=0;i<n;i++)
                up[k][i]=up[k-1][up[k-1][i]];

        vector<int> ans;
        for(auto &x:queries){
            int u=pos[x[0]],v=pos[x[1]];
            if(u>v) swap(u,v);

            if(comp[u]!=comp[v]){
                ans.push_back(u==v?0:-1);
                continue;
            }

            if(u==v){
                ans.push_back(0);
                continue;
            }

            int cur=u,res=0;
            for(int k=LG-1;k>=0;k--)
                if(up[k][cur]<v){
                    cur=up[k][cur];
                    res+=1<<k;
                }

            ans.push_back(res+1);
        }
        return ans;
    }
};
