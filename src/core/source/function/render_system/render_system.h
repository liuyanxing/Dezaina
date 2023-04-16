class RenderSystem {
public:
		RenderSystem();
		~RenderSystem();
		void tick();
		void render();
		void setWidth(int width);
		void setHeight(int height);
		void clear();
};