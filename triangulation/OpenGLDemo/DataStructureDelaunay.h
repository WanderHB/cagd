#pragma once

//������Ľ����
class CNode:public CObject
{
public:
	int index;//��������
	int x,y;//x��y����ֵ
	//bool out;//���⻷
	int NO_in;//�ڻ���ţ��⻷Ϊ0���ڻ���1��ʼ
	bool head;//�Ƿ�ͷ
	bool tail;//�Ƿ�β
public:
	CNode()
	{
		index=0;
		x=0;
		y=0;
		//out=TRUE;
		NO_in=0;
		head=FALSE;
		tail=FALSE;
	}//���ʼ��
	CNode(CNode *temp)
	{
		index=temp->index;
		x=temp->x;
		y=temp->y;
		//out=temp->out;
		NO_in=temp->NO_in;
		head=temp->head;
		tail=temp->tail;
	}
	CNode(CNode &n)
	{
		index=n.index;
		x=n.x;
		y=n.y;
		//out=n.out;
		NO_in=n.NO_in;
		head=n.head;
		tail=n.tail;
	}
	CNode& operator =(CNode n)
	{
		index=n.index;
		x=n.x;
		y=n.y;
		//out=n.out;
		NO_in=n.NO_in;
		head=n.head;
		tail=n.tail;
		return *this;
	}
#ifdef _DEBUG
    void Dump( CDumpContext& dc ) const
    {
        //CObject::Dump( dc );
        dc << index;
    }
#endif
};

//����������Ľ����
class CTriange:public CObject
{
public:
	int index;//��������
	int L1,L2,L3;//�����ε��������������
public:
	CTriange()
	{
		index=0;
		L1=0;
		L2=0;
		L3=0;
	}//���ʼ��
	CTriange(CTriange *temp)
	{
		index=temp->index;
		L1=temp->L1;
		L2=temp->L2;
		L3=temp->L3;
	}
	CTriange(CTriange &t)
	{
		index=t.index;
		L1=t.L1;
		L2=t.L2;
		L3=t.L3;
	}
	CTriange& operator =(CTriange t)
	{
		index=t.index;
		L1=t.L1;
		L2=t.L1;
		L3=t.L3;
		return *this;
	}
#ifdef _DEBUG
    void Dump( CDumpContext& dc ) const
    {
        //CObject::Dump( dc );
        dc << index<<":"<<L1<<","<<L2<<","<<L3;
    }
#endif

};
//������ı���
class CEdge:public CObject
{
public:
	int index;//��������
	int L1,L2;//�ߵ��������������
public:
	CEdge()
	{
		index=0;
		L1=0;
		L2=0;
	}//���ʼ��
	CEdge(CEdge *temp)
	{
		index=temp->index;
		L1=temp->L1;
		L2=temp->L2;
	}
	CEdge(CEdge &t)
	{
		index=t.index;
		L1=t.L1;
		L2=t.L2;
	}
	CEdge& operator =(CEdge t)
	{
		index=t.index;
		L1=t.L1;
		L2=t.L2;
		return *this;
	}
#ifdef _DEBUG
    void Dump( CDumpContext& dc ) const
    {
		//CObject::Dump( dc );
        dc << index<<":"<<L1<<","<<L2;
    }
#endif
};
