/***************************************Copyright(c)************************************************
****************************************************************************************************
***** ��    �� :Dev_FIFO.c
***** ��    �� :sevenblock
***** ��    �� :
***** ��    �� :V1.0
***** ʱ    �� :2017-05-03
***** ��    ע :
****************************************************************************************************
***************************************************************************************************/
#define Dev_FIFO_D
#include "..\block\app\App_Macro.h"


/*
****************************************************************************************************
** ��    �� ��Dev_FIFO_Init()
** ��    �� ��
** ��ڲ��� ����
** ���ڲ��� ����
** ��    �� ��
** ��    ע ��
****************************************************************************************************
*/
void Dev_FIFO_Init(STRUCT_COM_FIFO *t_puFifo, u8 *t_paBuf, u16 t_rSize)
{
	t_puFifo->m_pData = t_paBuf;
	t_puFifo->m_Depth = t_rSize;
	t_puFifo->m_ValidSize = 0;
	t_puFifo->m_InOffset = 0;
	t_puFifo->m_OutOffset = 0;
}

/*
****************************************************************************************************
** ��    �� ��Dev_FIFO_Put()
** ��    �� ��
** ��ڲ��� ����
** ���ڲ��� ����
** ��    �� ��
** ��    ע ��
****************************************************************************************************
*/
s32 Dev_FIFO_Put(STRUCT_COM_FIFO *t_puFifo, u8 *t_paData, u16 t_rDataLen)
{
	u16 i;
	
	if((t_puFifo->m_ValidSize + t_rDataLen) > t_puFifo->m_Depth)
	{
		return 1;
	}

	for(i=0;i<t_rDataLen;i++)
	{
		t_puFifo->m_pData[t_puFifo->m_InOffset++] = t_paData[i];

		if(t_puFifo->m_InOffset == t_puFifo->m_Depth)
		{
			t_puFifo->m_InOffset = 0;
		}

		t_puFifo->m_ValidSize++;
	}

	return 0;
}

/*
****************************************************************************************************
** ��    �� ��Dev_FIFO_Get()
** ��    �� ��
** ��ڲ��� ����
** ���ڲ��� ����
** ��    �� ��
** ��    ע ��
****************************************************************************************************
*/
s32 Dev_FIFO_Get(STRUCT_COM_FIFO *t_puFifo, u8 *t_paData, u16 t_rDataLen)
{
	u16 i;
	
	if(t_puFifo->m_ValidSize < t_rDataLen)
	{
		return 0;
	}
	
	for(i=0;i<t_rDataLen;i++)
	{
		t_paData[i] = t_puFifo->m_pData[t_puFifo->m_OutOffset++];

		if(t_puFifo->m_OutOffset == t_puFifo->m_Depth)
		{
			t_puFifo->m_OutOffset = 0;
		}

		t_puFifo->m_ValidSize--;
	}

	return 1;
}

/*
****************************************************************************************************
** ��    �� ��Dev_FIFO_FreeSize()
** ��    �� ��
** ��ڲ��� ����
** ���ڲ��� ����
** ��    �� ��
** ��    ע ��
****************************************************************************************************
*/
u16 Dev_FIFO_FreeSize(STRUCT_COM_FIFO *t_puFifo)
{
	return (t_puFifo->m_Depth - t_puFifo->m_ValidSize);
}

/****************************************End Of File************************************************
***************************************************************************************************/
