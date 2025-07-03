#include <xc.h>

static unsigned int count =0;
extern unsigned char sec,min;
void __interrupt() isr( void )
{
    if(TMR2IF==1)
    {
        if( ++count == 20000) 
        {
            if(sec!=0)
                sec--;
            else if(sec==0 && min!=0){
                min--;
                sec=60;
            }
            count = 0;
            
            
        }
        
        TMR2IF = 0; // clear interrupt flag 
        
    }
    
    
}

