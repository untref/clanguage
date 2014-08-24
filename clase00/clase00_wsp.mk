.PHONY: clean All

All:
	@echo "----------Building project:[ clase00 - Debug ]----------"
	@$(MAKE) -f  "clase00.mk"
clean:
	@echo "----------Cleaning project:[ clase00 - Debug ]----------"
	@$(MAKE) -f  "clase00.mk" clean
