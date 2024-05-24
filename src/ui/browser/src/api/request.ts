import axios from "axios";

export const request = axios.create({
  baseURL: "/",
  timeout: 30000
});

type ErrorCallback = (error: any) => void;

const errorCallbacks: Record<number, Array<ErrorCallback>> = {};

request.interceptors.response.use(
  (response) => response,
  (error) => {
    const callbacks = errorCallbacks[error.response.status];
    if (callbacks) {
      callbacks.forEach((callback) => {
        callback(error);
      });
    }
  }
)

export function registerErrorCallback(errorStatus: number, callback: ErrorCallback) {
  if (!errorCallbacks[errorStatus]) {
    errorCallbacks[errorStatus] = [];
  }
  errorCallbacks[errorStatus].push(callback);
}