#pragma once
#include "CScene.h"


class CScene_Start :
    public CScene
{
public:
    // virtual은 상속 받은 함수라는걸 표시하기위해.
    // 안붙여도 작동은 가능
    virtual void Enter();
    virtual void Exit();

public:
    CScene_Start();
    ~CScene_Start();
};

