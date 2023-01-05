#include "variable.h"

Asuransi asr;
float bleasing;
float basuransi;
float badmin;

void BungaLeasing()
{
    if(asr.tenor_thn == 1)
    {
        bleasing = 0.03;
    } else if(asr.tenor_thn == 2)
    {
        bleasing = 0.04;
    } else if(asr.tenor_thn == 3)
    {
        bleasing = 0.05;
    } else if(asr.tenor_thn == 4)
    {
        bleasing = 0.06;
    } else if(asr.tenor_thn == 5)
    {
        bleasing = 0.07;
    }
}

void TLO()
{
    if(asr.tenor_thn == 1)
    {
        basuransi = 0.01;
    } else if(asr.tenor_thn == 2)
    {
        basuransi = 0,0185;
    } else if(asr.tenor_thn == 3)
    {
        basuransi = 0.0275;
    } else if(asr.tenor_thn == 4)
    {
        basuransi = 0.036;
    } else if(asr.tenor_thn == 5)
    {
        basuransi = 0.045;
    }
}

void allrisk()
{
    if(asr.tenor_thn == 1)
    {
        basuransi = 0.03;
    } else if(asr.tenor_thn == 2)
    {
        basuransi = 0,054;
    } else if(asr.tenor_thn == 3)
    {
        basuransi = 0.078;
    } else if(asr.tenor_thn == 4)
    {
        basuransi = 0.105;
    } else if(asr.tenor_thn == 5)
    {
        basuransi = 0.125;
    }
}

void BiayaAdmin()
{
    if(asr.tenor_thn == 1)
    {
        badmin = 1000000;
    } else if(asr.tenor_thn == 2)
    {
        badmin = 1500000;
    } else if(asr.tenor_thn == 3)
    {
        badmin = 2000000;
    } else if(asr.tenor_thn == 4)
    {
        badmin = 2500000;
    } else if(asr.tenor_thn == 5)
    {
        badmin = 3000000;
    }
}
