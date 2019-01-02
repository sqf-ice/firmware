/***************************************Copyright(c)************************************************
****************************************************************************************************
***** ��    �� :Dev_Spi.h
***** ��    �� :sevenblock
***** ��    �� :
***** ��    �� :V1.0
***** ʱ    �� :2017-05-03
***** ��    ע :
****************************************************************************************************
***************************************************************************************************/
#ifndef Dev_Spi_H
#define Dev_Spi_H

#ifndef Dev_Spi_D
#define EX_Dev_Spi		extern
#else
#define EX_Dev_Spi
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************�궨��****************************************************
***************************************************************************************************/
#define SPI_LCD_CS							11
#define SPI_FLASH_CS						5

/****************************************���ܶ���***************************************************
***************************************************************************************************/
EX_Dev_Spi void  Spi_Enable (u8 uCS);
EX_Dev_Spi void  Spi_Disable (u8 uCS);
EX_Dev_Spi void  Spi_Send_Byte (u8 ucData);
EX_Dev_Spi void  Spi_Comm(u8  *pucTxBuf, u16  ucTxNum,u8  *pucRxBuf, u16  ucRxNum);
EX_Dev_Spi void  Spi_Init (void);

#ifdef __cplusplus
}
#endif
#endif
/****************************************End Of File************************************************
***************************************************************************************************/
