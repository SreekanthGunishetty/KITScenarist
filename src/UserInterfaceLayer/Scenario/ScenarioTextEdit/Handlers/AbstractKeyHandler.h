#ifndef ABSTRACTKEYHANDLER_H
#define ABSTRACTKEYHANDLER_H

class ScenarioTextEdit;
class QKeyEvent;


namespace KeyProcessingLayer
{
	/**
	 * @brief Базовый класс обработчика нажатия клавиш
	 */
	class AbstractKeyHandler
	{
	public:
		explicit AbstractKeyHandler(ScenarioTextEdit* _editor);
		virtual ~AbstractKeyHandler();

		/**
		 * @brief Обработка события нажатия клавиши
		 */
		void handle(QKeyEvent* _event);

	protected:
		/**
		 * @brief Подготовка к обработке
		 */
		virtual void prepareForHandle() {}

		/**
		 * @brief Необходимые действия при нажатии конкретной клавиши/сочетания
		 */
		/** @{ */
		virtual void handleShortcut(QKeyEvent* _event = 0) = 0;
		virtual void handleEnter(QKeyEvent* _event = 0) = 0;
		virtual void handleTab(QKeyEvent* _event = 0) = 0;
		virtual void handleDelete(QKeyEvent* _event = 0) = 0;
		virtual void handleBackspace(QKeyEvent* _event = 0) = 0;
		virtual void handleEscape(QKeyEvent* _event = 0) = 0;
		virtual void handleUp(QKeyEvent* _event = 0) = 0;
		virtual void handleDown(QKeyEvent* _event = 0) = 0;
		virtual void handleOther(QKeyEvent* _event = 0) = 0;
		/** @} */

	protected:
		/**
		 * @brief Получить текстовый редактор, с которым ассоциирован данный обработчик
		 */
		ScenarioTextEdit* editor() const;

	private:
		/**
		 * @brief Текстовый редактор, с которым ассоциирован данный обработчик
		 */
		ScenarioTextEdit* m_editor;
	};
}

#endif // ABSTRACTKEYHANDLER_H