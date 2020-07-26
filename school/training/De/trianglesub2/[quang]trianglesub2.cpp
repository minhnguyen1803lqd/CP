#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "trianglesub2";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out[quang]").c_str(), "w", stdout)

cll maxn = 15e2 + 7;
struct point{
    ll x, y;
}p[maxn];
struct line{
    ll a, b, c;
};
ll n, ans = 0;

bool operator <(point const &l, point const &r){
    return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y));
}

bool operator <(line const &l, line const &r){
    return (l.a < r.a) || (l.a == r.a && l.b < r.b) || (l.a == r.a && l.b == r.b && l.c < r.c);
}

bool operator ==(point const &l, point const &r){
    return (l.x == r.x && l.y == r.y);
}

vec(point) alvt;
map<line, ll> cntp;

void xl(){
    sort(p + 1, p + 1 + n);
    vec(point) vtmp;
    lp(i, 1, n){
        if(!(p[i] == p[i - 1])) vtmp.push_back(p[i]);
    }
    n = vtmp.size();
    lp(i, 1, n){
        p[i] = vtmp[i - 1];
    }
}

void rg(point &p1){
    ll r = __gcd(abs(p1.x), abs(p1.y));
    if(!r) r = 1;
    p1.x /= r, p1.y /= r;
    if(p1.x < 0) p1.x *= -1, p1.y *= -1;
}

void getPT(point &p1, point &p2, point &pr, point &pt, point &cp){
    cp = {p2.x - p1.x, p2.y - p1.y};
    rg(cp);
    pt = {-cp.y, cp.x};
    rg(pt);
    pr = p1;
}

void getabc(line &d, point &pt, point &pr){
    d.a = pt.x, d.b = pt.y; d.c = -(pt.x*pr.x + pt.y*pr.y);
    ll r = __gcd(abs(d.a), __gcd(abs(d.b), abs(d.c)));
    if(!r) r = 1;
    d.a /= r, d.b /= r, d.c /= r;
}

void xld(line &d){
    if(d.a < 0) d.a *= -1, d.b *= -1, d.c *= -1;
}

bool check(line &d, point &pnt){
    return !(d.a * pnt.x + d.b * pnt.y + d.c);
}

void prc(){
    vec(line) aldt;
    map<line, ll> cntdt;
    map<point, ll> cntvt;
    line tmp;
    point p1, p2, pr, pt, cp;
    lp(i, 1, n){
        lp(j, i + 1, n){ //moi vector u = vt ij tim cac diem tao voi diem i la vector phap tuyen cua vt ij
            p1 = p[i], p2 = p[j];
            getPT(p1, p2, pr, pt, cp);
            getabc(tmp, pt, pr);
            xld(tmp);
            if(!cntdt[tmp]++) aldt.push_back(tmp);
            if(!cntvt[cp]++) alvt.push_back(cp);
        }   
    }
    lp(i, 1, n){
        lp(j, 0, aldt.size() - 1){
            if(check(aldt[j], p[i])) ++cntp[aldt[j]];
        }
    }
}

line getLine(point pt, point p1){
    line tmp;
    tmp.a = pt.x, tmp.b = pt.y;
    tmp.c = -(pt.x * p1.x + pt.y * p1.y);
    ll r = __gcd(abs(tmp.a), __gcd(abs(tmp.b), abs(tmp.c)));
    if(!r) r = 1;
    tmp.a /= r, tmp.b /= r, tmp.c /= r;
    xld(tmp);
    return tmp;
}

void cnttg(){
    map<point, ll> dau;
    line l1, l2;
    point p1, p2;
    lp(i, 1, n){
        dau.clear();
        lp(j, 0, alvt.size() - 1){
            if(dau[alvt[j]]) continue;
            p1 = alvt[j];
            p2 = {-p1.y, p1.x};
            rg(p2);
            l1 = getLine(p2, p[i]), l2 = getLine(p1, p[i]);
            if(cntp[l1] && cntp[l2]) ans += (cntp[l1] - 1) * (cntp[l2] - 1), dau[p1] = 1, dau[p2] = 1;
        }
    }
}

void fs(ll &number) 
{ 
    bool negative = false; 
    register int c; 

    number = 0; 
    c = getchar(); 
    if (c == ' ') fs(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

ii main(){
    opt;
    file;
    fs(n);
    lp(i, 1, n){
        fs(p[i].x); fs(p[i].y);
    }
    //xl();
    prc();
    cnttg();
    cout << ans;
}
