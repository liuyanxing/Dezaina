import { request } from "./request";

export async function isLoginOrRedirect() {
  const res = await request.get('/api/user');
  console.log(res);
  return res;
}

export async function login(accout: string, password: string) {
  await request.post('/api/session/login', {
    email: accout,
    password: password,
    username: accout,
  })
}