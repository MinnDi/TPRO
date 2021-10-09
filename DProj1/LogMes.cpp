/*!
 \version 1.3
 \date 02.10.2021
 \ref LoggerController
 \brief Метод с логикой логирования
 \param message Сохраняемое сообщение
 \throw SaveException При ошибке сохранения
 \throw NullPointerException При передаче пустого сообщения
 \code
 log("Hi!");
 log(message);
 \endcode
 */
    public void log(Message message) throws SaveException, NullPointerException {
        try {
            if (message == null) {
                throw new NullPointerException("There is no message");
            } else if (message.getValue() == null) {
                throw new NullPointerException("Message is empty");
            }
        } catch (NullPointerException e) {
            e.printStackTrace();
            throw e;
        }
        try {
            if (state == State.NULL) {
                lastMessage = message;
                state = State.NOT_NULL;
            } else if (message.typeEquals(lastMessage)) {
                lastMessage.accumulate(message);
            } else {
                lastMessage.close();
                saver.save(lastMessage.decorate());
                lastMessage = message;
            }
        }
        catch (SaveException e){
            e.printStackTrace();
            throw e;
        }
    }
\\ Это добавленный комментарий
