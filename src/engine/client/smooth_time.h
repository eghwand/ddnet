/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */

#ifndef ENGINE_CLIENT_SMOOTH_TIME_H
#define ENGINE_CLIENT_SMOOTH_TIME_H

#include "graph.h"

#include <cstdint>

class CSmoothTime
{
	int64_t m_Snap;
	int64_t m_Current;
	int64_t m_Target;

	int64_t m_SnapMargin;
	int64_t m_CurrentMargin;
	int64_t m_TargetMargin;

	CGraph m_Graph;

	int m_SpikeCounter;

	float m_aAdjustSpeed[2]; // 0 = down, 1 = up
public:
	void Init(int64_t Target);
	void SetAdjustSpeed(int Direction, float Value);

	int64_t Get(int64_t Now);

	void UpdateInt(int64_t Target);
	void Update(CGraph *pGraph, int64_t Target, int TimeLeft, int AdjustDirection);

	int64_t GetMargin(int64_t Now);
	void UpdateMargin(int64_t TargetMargin);
};

#endif
