#pragma once

#include "interface.hpp"

#include <unordered_map>
#include <vector>

namespace YellowRectangleCyanCircle {
	class Context : public IContext {
	public:
		Context();
		
		// Game information
		bool IsGameFound() const override final;
		void SetGameFound(bool value) override final;

		const Rect::Rect& GetGameRect() const override final;
		void SetGameRect(const Rect::Rect& rect) override final;

		// Detector information
		bool IsDetectorEnabled(DetectorType dt) const override final;
		void SetDetectorEnabled(DetectorType dt, bool value) override final;

		const Rect::Rect& GetWorkingArea() const override final;
		void SetWorkingArea(const Rect::Rect& value) override final;

		// Keypad detector specials
		unsigned int KeypadGetEmptyRunCounter() const override final;
		void KeypadRegisterEmptyRun() override final;
		void KeypadClearEmptyRunCounter() override final;

		const std::vector<std::shared_ptr<IShape>>& KeypadGetShapesCache() const override final;
		void KeypadSetShapesCache(const std::vector<std::shared_ptr<IShape>>& value) override final;
		void KeypadClearShapesCache() override final;

		// Screen infoction
		const Mat& GetScreenImage() const override final;
		void SetScreenImage(const Mat& value) override final;

		// Shape information
		std::vector<std::shared_ptr<IShape>> GetShapes(DetectorType dt) const override final;
		void SetShapes(DetectorType dt, const std::vector<std::shared_ptr<IShape>>& shapes) override final;
		void ClearShapes(DetectorType dt) override final;
	private:
		bool isGameFound = false;
		Rect::Rect gameRect;

		std::unordered_map<DetectorType, bool> detectorStates;

		unsigned int keypadEmptyRunCounter = 0;
		std::vector<std::shared_ptr<IShape>> keypadShapesCache;
		
		Rect::Rect workingArea;

		Mat screenImage;

		std::unordered_map<DetectorType, std::vector<std::shared_ptr<IShape>>> detectorShapes;
	};
}