#ifndef I_OBSERVER_H
#define I_OBSERVER_H

namespace PlantsVs {
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Notify(int code) = 0;
};  
}


#endif // I_OBSERVER_H