int test_v(long v)
{
    int a,b,c,final;
    a = v;
    b = 2 * v;
    c = 3 * v;
    final = a + b + c;
    return final == 60;
}

int stack(long v)
{
    int ret_value;
    ret_value = test_v(v);
    return ret_value;
}
