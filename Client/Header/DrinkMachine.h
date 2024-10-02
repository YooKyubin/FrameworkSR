#pragma once
#include "GameObject.h"
#include "../Header/Player.h"
#include "../Header/Drink.h"

BEGIN(Engine)

class CRcTex;
class CRcCol;
class CTexture;
class CCalculator;
class CTransform;
class CCollider;
class CAnimator;

END

class CDrinkMachine :
    public CGameObject
{
public:
    enum DRINKMACHINESTATE {MACHINE_IDLE, MACHINE_ACTIVE, MACHINE_BROKEN, MACHINE_END};
private:
    explicit CDrinkMachine(LPDIRECT3DDEVICE9 _pGraphicDev);
    virtual ~CDrinkMachine();

public:
    static CDrinkMachine* Create(LPDIRECT3DDEVICE9 _pGraphicDev);

public:
    virtual HRESULT	Ready_GameObject();
    virtual _int Update_GameObject(const _float& _fTimeDelta);
    virtual void LateUpdate_GameObject();
    virtual void Render_GameObject();

public:
    virtual void OnCollisionEnter(CCollider& _pOther);

private:
    virtual HRESULT	Add_Component();
    virtual void Set_Animation();
    void Spawn_Drink();
    void State_Check();

private:
    Engine::CRcTex* m_pBufferCom;
    Engine::CCollider* m_pColliderCom;
    //Engine::CRcCol* m_pHitBufferCom;
    //Engine::CRcCol* m_pHeadHit;
    //Engine::CRcCol* m_pCriticalHit;
    Engine::CTexture* m_pTextureCom[DRINKMACHINESTATE::MACHINE_END];
    Engine::CCalculator* m_pCalculatorCom;

    Engine::CAnimator* m_pAnimatorCom;
    Engine::CTransform* m_pTransformCom;

    _bool m_bIsDead;
    DRINKMACHINESTATE m_eCurState;
    DRINKMACHINESTATE m_ePreState;

private:
    virtual void Free();
};

