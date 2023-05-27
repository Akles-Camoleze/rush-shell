TARGET=main
LD=gcc
BUILD_DIR = build
OBJS=main.o exceptions.o allocation.service.o commandline.service.o engine.service.o file.service.o messages.view.o
RUN=build/main.o build/exceptions.o build/allocation.service.o build/commandline.service.o build/engine.service.o build/file.service.o build/messages.view.o

all: $(OBJS)
	@$(LD) $(RUN) -o $(TARGET) && clear; ./$(TARGET)

exceptions.o: io-exceptions/exceptions.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c io-exceptions/exceptions.c -o $(BUILD_DIR)/exceptions.o

commandline.service.o: services/commandline/commandline.service.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c services/commandline/commandline.service.c -o $(BUILD_DIR)/commandline.service.o

allocation.service.o: services/allocation/allocation.service.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c services/allocation/allocation.service.c -o $(BUILD_DIR)/allocation.service.o

engine.service.o: services/engine/engine.service.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c services/engine/engine.service.c -o $(BUILD_DIR)/engine.service.o

file.service.o: services/file/file.service.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c services/file/file.service.c -o $(BUILD_DIR)/file.service.o

messages.view.o: views/messages/messages.view.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c views/messages/messages.view.c -o $(BUILD_DIR)/messages.view.o

main.o: main.c
	@if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
	@$(LD) -c main.c -o $(BUILD_DIR)/main.o

debug:
	@$(LD) -g $(OBJS) -o $(TARGET)

clean:
	@rm -f $(BUILD_DIR)/*.o