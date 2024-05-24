import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [react()],
  server: {
    proxy: {
      '/api/user': {
        target: 'https://www.figma.com',
        changeOrigin: true,
        headers: {
          'Cookie': 'aws-waf-token=4ff1e23d-b00d-4be3-a04c-5cff00b3dab1:EwoAiw8WhY1uAAAA:SrvUVW1aQuOJiqkowdy7Tcwy0Nnc4PfUEL2ZR26vCrV/rqrZqrbqOCYoLtoffQpvpfRqaVQL22Gik/X4W9fJiUthZOzUfjdz05IOkfiL8X649szlIQv5Od5+0BdUEsKDTxK6GHCCZMwlOnR5idbu6Ux8STTfyqXjFK1gunJ7zv9lA4c+ofrJ0oe9LoQ=' // 例如，设置 Authorization 头  
        }
      },
      '/api': {
        target: 'https://www.figma.com',
        changeOrigin: true,
      }
    }
  }
})
