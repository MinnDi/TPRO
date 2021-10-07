/*!
 \version 1.3
 \date 02.10.2021
 \ref FileSaver
 \brief Переопределенный метод, сохраняющий информацию
 \param message Сохраняемое сообщение
 \throw SaveException При ошибке сохранения
 \code
 save("Hi!");
 save(message);
 \endcode
 */
    @Override
    public void save(String message) throws SaveException {
        try (BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream(outputFile), size), charSet))) {
            out.write(message);
            System.out.println("log save to file");
        } catch (FileNotFoundException e) {
            throw new SaveException("File not found", e);
        } catch (IOException e) {
            throw new SaveException("Input/output error", e);
        }
    }

///Enum State of previous message
public enum State {
    NOT_NULL, ///< Не пустое, но не учитывается при следующем сообщении
    NULL, ///< Сообщения до не было
    INTS, ///< Прошлое сообщение было типа int
    STRINGS ///< Прошлое сообщение было типа String
}