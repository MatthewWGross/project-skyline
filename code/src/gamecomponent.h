#pragma once

enum class eGameComponentType
{
    AIRPLANE,
    AIRPORT,
    RENDER,
    COUNT,
    INVALID
};

class GameObject;

class IGameComponent
{
public:
    virtual ~IGameComponent() {}
    eGameComponentType GetType() const { return m_type; } 
    GameObject *GetParent() const { return m_parent; }
    bool IsOwnedByParent() const { return m_ownedByParent; }

    virtual void OnParentDestroyed() {m_parent = nullptr; } // called right before parent is destroyed

protected:
    IGameComponent(eGameComponentType type, GameObject *parent)
    {
        m_type = type;
        m_parent = parent;
    }

    void SetOwnedByParent(bool val){m_ownedByParent = val;}

private:
    eGameComponentType m_type = eGameComponentType::INVALID;
    GameObject *m_parent = nullptr;
    bool m_ownedByParent = true; // if true, the parent will delete this in it's dtor
};