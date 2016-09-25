BEGIN{
    s = 0; 
    sq = 0;
}
{
    j = 0;
    for(i = 3; i <= NF; ++i)
    {
        s += $i;
        a[j++] = $i;
    }
}
END{
    s_avg = s/(NF-2);
    for(j = 0; j <= NF-2; j++)
        sq += (a[j] - s_avg)^2
    printf("%f\n",sqrt(sq/(NF-3)))
}
