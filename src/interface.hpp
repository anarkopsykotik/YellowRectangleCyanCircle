#pragma once

#include "types.hpp"

#include <memory>
#include <shared_mutex>
#include <vector>

namespace YellowRectangleCyanCircle {
    struct IShape {
        virtual void OnDraw(
            const CComPtr<ID2D1HwndRenderTarget>& target,
            const CComPtr<ID2D1SolidColorBrush>& brush
        ) const = 0;
    };

    struct IContext {
        // Context

        // Locks
        virtual std::shared_lock<std::shared_mutex> LockOnRead() = 0;
        virtual std::unique_lock<std::shared_mutex> LockOnWrite() = 0;

        // Clear on-time variables
        virtual void ClearOnTick() = 0;

        // Game information
        virtual bool IsGameFound() const = 0;
        virtual void SetGameFound(bool value) = 0;

        virtual const Rect::Rect& GetGameRect() const = 0;
        virtual void SetGameRect(const Rect::Rect& rect) = 0;

        // Detector information
        virtual bool IsDetectorEnabled(DetectorType dt) const = 0;
        virtual void SetDetectorEnabled(DetectorType dt, bool value) = 0;

        virtual const Rect::Rect& GetWorkingArea() const = 0;
        virtual void SetWorkingArea(const Rect::Rect& value) = 0;
        virtual const Rect::Rect& GetPreviousWorkingArea() const = 0;

        // Keypad detector specials
        const unsigned int KeypadMaxEmptyCirclesInRow = 3;

        virtual unsigned int KeypadGetEmptyRunCounter() const = 0;
        virtual void KeypadRegisterEmptyRun() = 0;
        virtual void KeypadClearEmptyRunCounter() = 0;

        virtual const std::vector<std::shared_ptr<IShape>>& KeypadGetShapesCache() const = 0;
        virtual void KeypadSetShapesCache(const std::vector<std::shared_ptr<IShape>>& value) = 0;
        virtual void KeypadClearShapesCache() = 0;

        // Screen infoction
        virtual const Mat& GetScreenImage() const = 0;
        virtual void SetScreenImage(const Mat& value) = 0;

        // Shape information
        virtual std::vector<std::shared_ptr<IShape>> GetShapes(DetectorType dt) const = 0;
        virtual void SetShapes(DetectorType dt, const std::vector<std::shared_ptr<IShape>>& shapes) = 0;
        virtual void ClearShapes(DetectorType dt) = 0;

        virtual bool IsShapesChanged(DetectorType dt) const = 0;
        virtual void SetShapesChanged(DetectorType dt, bool value) = 0;

        // Game window information
        virtual HWND GetWindowHandle() const = 0;
        virtual void SetWindowHandle(HWND value) = 0;
    };

    struct IAction {
        virtual void Perform(IContext& context) = 0;
    };

    struct IHook {
        virtual void Enable() = 0;
        virtual void Disable() = 0;

        virtual bool IsEnabled() const noexcept = 0;
    };

    struct IWindowCallbackReceiver {
        virtual void OnWindowCreated(HWND hWnd) {};
        virtual void OnWindowDestroyed(HWND hWnd) {};
        virtual void OnWindowMoved(HWND hWnd) {};
    };
}
