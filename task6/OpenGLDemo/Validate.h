#include "stdafx.h"
#include "CP_Topology.h"

/*
	ʹ�÷�������Validate.h������Ŀ�ļ����ڣ�Ȼ������Ŀ��ͷ�ļ������Validate.h��
		����Ҫ��֤Brep��ȷ�Ե��ļ���#include "Validate.h"��
		ͨ������validate_body(CP_Body& b)����֤Brep�Ƿ���ȷ��
	���磺
		cf_bodyCylinderCreate(b, 0.0, 0.0, -h/2, h, 2);
		validate_body(b);
	ע�⣺��Ϊ�ú���ʹ����assert()���������Ըú���ֻ����Debugģʽ�²���Ч��
*/

// ��֤body�������Ƿ���ȷ
bool validate_body(CP_Body& b)
{
    bool no_error = true;
    for (int face_index = 0; face_index < b.mf_getFaceNumber(); face_index++)
    {
        CP_Face *face = b.mf_getFace(face_index);
        // ÿ������⻷����Ϊ��
        assert(face->mf_getLoopNumber() >= 1);
        for (int loop_index = 0; loop_index < face->mf_getLoopNumber(); loop_index++)
        {
            CP_Loop *loop = face->mf_getLoop(loop_index);
            // ÿ����������һ��coedge
            assert(loop->mf_getCoedgeNumber() >= 1);
            for (int coedge_index = 0; coedge_index < loop->mf_getCoedgeNumber(); coedge_index++)
            {
                CP_Coedge *current_coedge = loop->mf_getCoedge(coedge_index);
                // ÿһ��edge����Ҫ������coedge
                assert(current_coedge->m_edge->mf_getCoedgeNumber() >= 2);
                int next_coedge_index = (coedge_index + 1) % loop->mf_getCoedgeNumber();
                CP_Coedge *next_coedge = loop->mf_getCoedge(next_coedge_index);

                CP_Vertex *current_coedge_end_vertex = current_coedge->m_sameDirection ? current_coedge->m_edge->m_endingVertex : current_coedge->m_edge->m_startingVertex;
                CP_Vertex *next_coedge_start_vertex = next_coedge->m_sameDirection ? next_coedge->m_edge->m_startingVertex : next_coedge->m_edge->m_endingVertex;
                // ÿһ��loop��coedgeҪ�ɻ�
                assert(current_coedge_end_vertex == next_coedge_start_vertex);
                assert((current_coedge->m_curve2D->mf_getEndingPoint() - next_coedge->m_curve2D->mf_getStartingPoint()).mf_getLength() == 0);
            }
        }
    }
    return no_error;
}