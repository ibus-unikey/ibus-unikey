#pragma once

#include "base/port.h"


class IPropertyHandler {
public:
    IPropertyHandler() {}
    virtual ~IPropertyHandler() {}

    // Registers current properties into engine.
    virtual void Register(IBusEngine *engine) = 0;

    virtual void ResetContentType(IBusEngine *engine) = 0;
    virtual void UpdateContentType(IBusEngine *engine) = 0;

    // Update properties.
    virtual void Update(IBusEngine *engine) = 0;

    virtual void ProcessPropertyActivate(IBusEngine *engine,
                                         const gchar *property_name,
                                         guint property_state) = 0;

    // Following two methods represent two aspects of an IME state.
    // * (activated, disabled) == (false, false)
    //     This is the state so-called "IME is off". However, an IME is expected
    //     to monitor keyevents that are assigned to DirectMode. A user should be
    //     able to turn on the IME by using shortcut or GUI menu.
    // * (activated, disabled) == (false, true)
    //     This is a state where an IME is expected to do nothing. A user should
    //     be unable to turn on the IME by using shortcut nor GUI menu. This state
    //     is used mainly on the password field. IME becomes to be "turned-off"
    //     once |disabled| state is flipped to false.
    // * (activated, disabled) == (true, false)
    //     This is the state so-called "IME is on". A user should be able to turn
    //     off the IME by using shortcut or GUI menu.
    // * (activated, disabled) == (true, true)
    //     This is the state where an IME is expected to do nothing. A user should
    //     be unable to turn on the IME by using shortcut nor GUI menu. This state
    //     is used mainly on the password field. IME becomes to be "turned-on"
    //     once |disabled| state is flipped to false.
    virtual bool IsActivated() const = 0;
    virtual bool IsDisabled() const = 0;

};

