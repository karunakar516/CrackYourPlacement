#define ll int

vector < ll > seg;
class SGT
{
    public: SGT(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(ll ind, ll low, ll high, vector < ll > & arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        ll mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        if (r < low || high < l) return 0;
        if (low >= l && high <= r) return seg[ind];

        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);

        return left + right;
    }

    void update(ll ind, ll low, ll high, ll i, ll val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        ll mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = (seg[ind * 2 + 1] + seg[2 * ind + 2]);
    }

};

class NumArray {
    public: 
    int n = 100;
    SGT sg = SGT(100);
    NumArray(vector < int > & nums) {
        n = nums.size();
        sg = SGT(n);
        sg.build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        sg.update(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return sg.query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */