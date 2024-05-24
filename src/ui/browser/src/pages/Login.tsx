import React, { useState } from 'react';

import { login } from "../api/session";

async function loginThenRedirect(accout: string, password: string) {
  await login(accout, password);
  window.location.href = "/";
}

function Login() {
  const [accout, setAccout] = useState('');
  const [password, setPassword] = useState('');

  return (
    <div className="login">
      <div>
        <label>账号</label><input type="text" value={accout} onChange={(e) => setAccout(e.target.value)} />
      </div>
      <div>
        <label>密码</label><input type="password" value={password} onChange={(e) => setPassword(e.target.value)} />
      </div>
      <button onClick={() => loginThenRedirect(accout, password)}>登录</button>
    </div>
  );
}

export {
  Login,
};
